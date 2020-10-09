import flask
from flask import request
from PIL import Image
from io import BytesIO
import base64
import pytesseract
import os



UPLOAD_FOLDER = 'C:\\Program Files\\Tesseract-OCR\\tesseract'
ALLOWED_EXTENSIONS = set(['txt', 'pdf', 'png', 'jpg', 'jpeg', 'gif'])
app = flask.Flask(__name__)
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER

def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS

@app.route('/', methods=['GET', 'POST'])
def upload_file():
    if request.method == 'POST':
        # check if the post request has the file part
        if 'imagefile' not in request.files:
            # flash('No file part')
            return redirect(request.url)
        file = request.files['imagefile']
        # if user does not select file, browser also
        # submit a empty part without filename
        if file.filename == '':
            # flash('No selected file')
            return redirect(request.url)
        if file and allowed_file(file.filename):
            filename = file.filename
            file.save(filename)
            return "<h1> Worked " + str(filename) + "</h1>"
    return '''
    <!doctype html>
    <title>Upload new File</title>
    <h1>Upload new File</h1>
    <form method=post enctype=multipart/form-data>
      <p><input type=file name=imagefile>
         <input type=submit value=Upload>
    </form>
    '''

@app.route('/upload', methods=['POST'])
def upload():
	print("hello")
	pytesseract.pytesseract.tesseract_cmd = 'C:\\Program Files\\Tesseract-OCR\\tesseract'
	imagefile = request.form.get('imagefile')
	im = Image.open(BytesIO(base64.b64decode(imagefile)))
	w, h = im.size
	im.save('temp.png', 'PNG')
	#im.save("temp.png")
	text=pytesseract.image_to_string(Image.open("temp.png"))
	file2write=open("writefile.txt",'wb')
	file2write.write(bytes(text, 'UTF-8'))
	file2write.close()
	return "<h1> Worked " + str(w) + "</h1>"


if __name__ == "__main__":
    #app.run(host='0.0.0.0')
    app.run(debug=True,host='0.0.0.0')
