const express = require('express');
const app = express();
app.use(express.urlencoded({ extended: true }));
const port = 3000;

// In-memory "customer table"
let customer = {
  id: 1,
  name: 'Rahul',
  balance: 5000
};

// Home page
app.get('/', (req, res) => {
  res.send(`
    <h2>Bank Account</h2>
    <form method="POST" action="/withdraw">
      <label>Withdraw Amount:</label><br>
      <input name="amount" type="number" required /><br><br>
      <button type="submit">Withdraw</button>
    </form><br>
    <form method="GET" action="/balance">
      <button type="submit">Check Balance</button>
    </form>
  `);
});

// Withdraw route
app.post('/withdraw', (req, res) => {
  const amount = parseFloat(req.body.amount);
  if (customer.balance - amount < 1000) {
    res.send(`Cannot withdraw ₹${amount}. Minimum balance ₹1000 must be maintained.`);
  } else {
    customer.balance -= amount;
    res.send(`₹${amount} withdrawn successfully. Remaining Balance: ₹${customer.balance}`);
  }
});

// Balance enquiry route
app.get('/balance', (req, res) => {
  res.send(`Current balance for ${customer.name}: ₹${customer.balance}`);
});

app.listen(port, () => {
  console.log(`Bank app running at http://localhost:${port}`);
});
