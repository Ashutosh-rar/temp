const express = require('express');
const path = require('path');
const app = express();
const port = 3000;

const places = [
  { id: 1, name: 'Taj Mahal', location: 'Agra, India', year: 1643 },
  { id: 2, name: 'Great Wall', location: 'China', year: '7th century BC' },
  { id: 3, name: 'Colosseum', location: 'Rome, Italy', year: 80 }
];

// Serve index.html from root
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

// API endpoint to get places
app.get('/places', (req, res) => {
  res.json(places);
});

app.listen(port, () => {
  console.log(`Portal running at http://localhost:${port}`);
});

