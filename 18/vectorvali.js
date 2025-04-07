const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

app.use(bodyParser.json());
app.use(express.static('public'));

let voters = [];


app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});


app.post('/add-voter', (req, res) => {
  const { name, age, nationality } = req.body;

  if (!/^[A-Z ]+$/.test(name)) {
    return res.status(400).json({ error: 'Name should be in upper case letters only' });
  }

  if (age < 18) {
    return res.status(400).json({ error: 'Age should not be less than 18 years' });
  }

  if (nationality.trim().toLowerCase() !== 'indian') {
    return res.status(400).json({ error: 'Nationality should be Indian' });
  }

  voters.push({ name, age, nationality });
  res.json({ message: 'Voter added successfully', voters });
});


app.get('/voters', (req, res) => {
  res.json(voters);
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});

//create index.html file
//npm install express body-parser
//run node vectorvali.js