const express = require('express');

const app = express();

const port = 3000;

const courses = [
{ id: 1, name: 'Introduction to Programming', credits: 3 },
{ id: 2, name: 'Data Structures', credits: 4 },
{ id: 3, name: 'Database Management', credits: 3 },
];

const faculty = [
{ id: 101, name: 'Mrs. Swapnal Nagwade ', specialization: 'Algorithms' },

{ id: 102, name: 'Mrs. Hemalata Chavan', specialization: 'Database Systems' },

];

app.get('/', (req, res) => {
res.send('Welcome to the Computer Science Department Portal');
});

app.get('/courses', (req, res) => {
res.json(courses);
});

app.get('/faculty', (req, res) => {
res.json(faculty);
});
app.listen(port, () => {
console.log(`Server is running at http://localhost:${port}`);
});