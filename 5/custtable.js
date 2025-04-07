const express = require('express');
const mysql = require('mysql');
const app = express();
const port = 3000;

app.use(express.urlencoded({ extended: true }));


const db = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: 'vcacs',
  database: 'hello'
});

db.connect(err => {
  if (err) throw err;
  console.log('Connected to database');
});


app.get('/', (req, res) => {
  db.query('SELECT * FROM customers', (err, results) => {
    if (err) throw err;
    let data = '<h2>Customer Records</h2><ul>';
    results.forEach(customer => {
      data += `<li>${customer.id}: ${customer.name} <a href='/delete/${customer.id}'>Delete</a></li>`;
    });
    data += '</ul>';
    res.send(data);
  });
});


app.get('/delete/:id', (req, res) => {
  const { id } = req.params;
  db.query('DELETE FROM customers WHERE id = ?', [id], (err, result) => {
    if (err) throw err;
    res.send('Record deleted successfully. <a href="/">Go Back</a>');
  });
});

app.listen(port, () => console.log(`Server running at http://localhost:${port}`));


// npm install express mysql

//create database in mysql

/* CREATE DATABASE hello;
   USE hello;
   CREATE TABLE customers (
   id INT AUTO_INCREMENT PRIMARY KEY,
   name VARCHAR(255) NOT NULL
   );

   INSERT INTO customers (name) VALUES ('John Doe'), ('Jane Smith'), ('Alice Johnson');
*/


