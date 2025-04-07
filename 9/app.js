const express = require('express');
const path = require('path');
const multer = require('multer');
const app = express();


const upload = multer({ dest: 'uploads/' });

app.use(express.static(path.join(__dirname, )));


app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});


app.post('/upload', upload.single('file'), (req, res) => {
  if (!req.file) {
    return res.send('No file uploaded!');
  }
  res.send(`File uploaded successfully: ${req.file.originalname}`);
});


app.listen(3000, () => {
  console.log('Server running at http://localhost:3000');
});



//create index.html file
//install: npm install express  ,  npm install express multer
//run: node app.js