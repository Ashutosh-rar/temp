const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const port = 3000;

let users = []; // Simple in-memory "database"

app.use(bodyParser.urlencoded({ extended: true }));

// Home page
app.get('/', (req, res) => {
  res.send(`<h2>Welcome</h2><a href="/register">Register</a> | <a href="/login">Login</a>`);
});

// Register page
app.get('/register', (req, res) => {
  res.send(`
    <h2>Register</h2>
    <form method="POST" action="/register">
      <input name="username" placeholder="Username" required /><br>
      <input name="password" placeholder="Password" type="password" required /><br>
      <button type="submit">Register</button>
    </form>
  `);
});

// Handle register
app.post('/register', (req, res) => {
  const { username, password } = req.body;
  users.push({ username, password });
  res.send(`User registered! <a href="/login">Login here</a>`);
});

// Login page
app.get('/login', (req, res) => {
  res.send(`
    <h2>Login</h2>
    <form method="POST" action="/login">
      <input name="username" placeholder="Username" required /><br>
      <input name="password" placeholder="Password" type="password" required /><br>
      <button type="submit">Login</button>
    </form>
  `);
});

// Handle login
app.post('/login', (req, res) => {
  const { username, password } = req.body;
  const found = users.find(u => u.username === username && u.password === password);
  if (found) {
    res.send(`Hello, ${username}! You are logged in.`);
  } else {
    res.send('Login failed. <a href="/login">Try again</a>');
  }
});

app.listen(port, () => {
  console.log(`Simple login app running at http://localhost:${port}`);
});
