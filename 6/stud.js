const mysql = require('mysql');


const db = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: 'vcacs',
  database: 'hello'
});

db.connect(err => {
  if (err) throw err;
  console.log('Connected to database');

 
  const students = [
    ['John', 'Doe', 20],
    ['Jane', 'Smith', 22],
    ['Alice', 'Johnson', 19]
  ];

  const sql = 'INSERT INTO student (first_name, last_name, age) VALUES ?';
  db.query(sql, [students], (err, result) => {
    if (err) throw err;
    console.log('Records inserted:', result);
    db.end();
  });
});


// npm install express mysql

//create database in mysql

/* CREATE DATABASE hello;
   USE hello;
   CREATE TABLE student (
   id INT AUTO_INCREMENT PRIMARY KEY,
   first_name VARCHAR(50),
   last_name VARCHAR(50),
   age INT
);

*/