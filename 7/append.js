const express = require('express');
const fs = require('fs');
const path = require('path');
const app = express();

app.use(express.urlencoded({ extended: true }));


app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});


app.post('/append', (req, res) => {
  const { file1, file2 } = req.body;

 
  if (!fs.existsSync(file1) || !fs.existsSync(file2)) {
    return res.send('One or both files do not exist.');
  }

  
  const data = fs.readFileSync(file1, 'utf8');
  fs.appendFileSync(file2, data);

  res.send('Contents of ' + file1 + ' have been appended to ' + file2);
});


app.listen(3000, () => {
  console.log('Server running at http://localhost:3000');
});

//make index.html file

//install: npm install express
//run : node append.js
