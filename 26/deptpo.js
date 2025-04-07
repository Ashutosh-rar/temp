// storePortal.js
const express = require('express');
const app = express();

app.use(express.json());

let products = [
  { id: 1, name: 'Shirt', price: 500 },
  { id: 2, name: 'Jeans', price: 1200 }
];

// Show all products
app.get('/products', (req, res) => {
  res.json(products);
});

// Add a product
app.post('/products', (req, res) => {
  products.push(req.body);
  res.send('Product added successfully!');
});

app.listen(3000, () => {
  console.log('Department Store Portal running on port 3000');
});
