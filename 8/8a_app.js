const express = require('express');
const fs = require('fs');
const path = require('path');
const app = express();

app.use(express.urlencoded({ extended: true }));


app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '8a_index.html'));
});


app.post('/combine', (req, res) => {
  const { file1, file2, outputFile } = req.body;

 
  if (!fs.existsSync(file1) || !fs.existsSync(file2)) {
    return res.send('One or both input files do not exist.');
  }

  
  const data1 = fs.readFileSync(file1, 'utf8');
  const data2 = fs.readFileSync(file2, 'utf8');
  const combinedData = (data1 + data2).toUpperCase();

  
  fs.writeFileSync(outputFile, combinedData);

  res.send('Content combined, converted to uppercase, and saved to ' + outputFile);
});


app.listen(3000, () => {
  console.log('Server running at http://localhost:3000');
});

//create 8a_index.html file
//install: npm install express
//run: node 8a_app.js
