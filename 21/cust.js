// miniStatement.js
const express = require('express');
const app = express();

const accounts = {
  101: [
    { date: '2025-04-01', amount: 1000, type: 'credit' },
    { date: '2025-04-03', amount: 200, type: 'debit' }
  ],
  102: [
    { date: '2025-04-02', amount: 5000, type: 'credit' }
  ]
};

app.get('/statement/:accountId', (req, res) => {
  const id = req.params.accountId;
  const statement = accounts[id];
  if (statement) {
    res.json(statement);
  } else {
    res.send('Account not found');
  }
});

app.listen(3001, () => {
  console.log('Mini Statement app running on port 3001');
});
