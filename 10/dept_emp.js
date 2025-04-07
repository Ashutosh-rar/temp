const express = require('express');
const { Sequelize, DataTypes } = require('sequelize');

const app = express();
const sequelize = new Sequelize('postgres://username:password@localhost:5432/your_database');
app.use(express.json());

const Department = sequelize.define('Department', { name: DataTypes.STRING });
const Employee = sequelize.define('Employee', { name: DataTypes.STRING, salary: DataTypes.FLOAT });
Department.hasMany(Employee);
Employee.belongsTo(Department);
sequelize.sync();

app.post('/departments', async (req, res) => res.json(await Department.create(req.body)));
app.post('/employees', async (req, res) => res.json(await Employee.create(req.body)));

app.get('/departments/:name/salaries', async (req, res) => {
  const dept = await Department.findOne({ where: { name: req.params.name }, include: Employee });
  if (!dept || !dept.Employees.length) return res.json({ min: 0, max: 0, avg: 0 });
  const salaries = dept.Employees.map(e => e.salary);
  res.json({ min: Math.min(...salaries), max: Math.max(...salaries), avg: salaries.reduce((a, b) => a + b, 0) / salaries.length });
});

app.listen(3000, () => console.log('Server running on http://localhost:3000'));


//CREATE DATABASE hello;
