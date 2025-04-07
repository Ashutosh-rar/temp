const mysql = require('mysql');


const db = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: 'vcacs',
  database: 'hello',
  port: "3306"
});

db.connect(err => {
  if (err) throw err;
  console.log('Connected to database');

  
  const sql = 'SELECT * FROM customers';
  db.query(sql, (err, result) => {
    if (err) throw err;
    console.log('Records:', result);
    db.end();
  });
});


//make sure database exist

// npm install express mysql

//create database in mysql

/* CREATE DATABASE hello;
   USE hello;
   CREATE TABLE customers (
  id INT AUTO_INCREMENT PRIMARY KEY,
  first_name VARCHAR(50) NOT NULL,
  last_name VARCHAR(50) NOT NULL,
  email VARCHAR(100),
  phone VARCHAR(15),
  address VARCHAR(255)
);


   INSERT INTO customers (first_name, last_name, email, phone, address)
VALUES
('John', 'Doe', 'john.doe@example.com', '1234567890', '123 Elm Street'),
('Jane', 'Smith', 'jane.smith@example.com', '9876543210', '456 Oak Avenue'),
('Alice', 'Johnson', 'alice.johnson@example.com', '5678901234', '789 Pine Road');

*/