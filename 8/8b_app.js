const express = require('express');
const path = require('path');
const app = express();

app.use(express.urlencoded({ extended: true }));


app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '8b_index.html'));
});


app.post('/register', (req, res) => {
  const { firstName, lastName, age } = req.body;

  const namePattern = /^[A-Za-z]+$/;
  const ageNumber = parseInt(age);

 
  if (!namePattern.test(firstName) || !namePattern.test(lastName)) {
    return res.send('Error: First name and last name should contain only letters.');
  }

  if (isNaN(ageNumber) || ageNumber < 6 || ageNumber > 25) {
    return res.send('Error: Age should be a number between 6 and 25.');
  }

  res.send('Student registered successfully!');
});


app.listen(3000, () => {
  console.log('Server running at http://localhost:3000');
});


//create 8b_index.html file
//install: npm install express
//run: node 8b_app.js