
const express = require('express');
const app = express();
app.use(express.urlencoded({ extended: true }));


app.get('/', (req, res) => res.sendFile(__dirname + 'index.html')); //index.html file path


app.post('/register', (req, res) => res.send(`Employee Registered: ${req.body.name}`));

app.listen(3000, () => console.log('Server running on http://localhost:3000'));

//create index.html file
