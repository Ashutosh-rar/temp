const express = require('express');
const app = express();
const port = 3000;

let employees = [
  { name: 'John', salary: 50000 },
  { name: 'Alice', salary: 70000 },
  { name: 'Bob', salary: 60000 },
];

app.get('/employees', (req, res) => {
  // Sort employees by salary
  employees.sort((a, b) => b.salary - a.salary);

  // Generate HTML table
  let html = `<h2>Employee Salary Table</h2><table border="1" cellpadding="5"><tr><th>Name</th><th>Salary</th></tr>`;
  employees.forEach(emp => {
    html += `<tr><td>${emp.name}</td><td>${emp.salary}</td></tr>`;
  });
  html += `</table>`;

  res.send(html);
});

app.listen(port, () => {
  console.log(`Employee server running at http://localhost:${port}/employees`);
});
