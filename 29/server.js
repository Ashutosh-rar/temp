const express = require('express');
const path = require('path');
const app = express();
const port = 3000;

const profiles = [
  { name: 'Asha', age: 25, profession: 'Doctor', location: 'Delhi' },
  { name: 'Ravi', age: 28, profession: 'Engineer', location: 'Mumbai' },
  { name: 'Neha', age: 26, profession: 'Teacher', location: 'Bangalore' }
];

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

app.get('/profiles', (req, res) => {
  res.json(profiles);
});

app.listen(port, () => {
  console.log(`💍 Matrimonial portal running at http://localhost:${port}`);
});
