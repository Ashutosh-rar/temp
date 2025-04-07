const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

// Middleware to parse JSON
app.use(bodyParser.json());

// Sample student data
let students = [
  { rno: 1, name: 'John Doe', marks: 85 },
  { rno: 2, name: 'Jane Doe', marks: 92 },
];

// Home route
app.get('/', (req, res) => {
  res.send('Welcome to the Student Information System');
});

// Get all students
app.get('/students', (req, res) => {
  res.json(students);
});

// Update marks for a student by roll number
app.put('/students/:rno', (req, res) => {
  const rno = parseInt(req.params.rno);
  const { marks } = req.body;

  // Find the student
  const student = students.find(s => s.rno === rno);

  // If student not found
  if (!student) {
    return res.status(404).json({ error: 'Student not found' });
  }

  // Validate marks
  if (typeof marks !== 'number' || marks < 0 || marks > 100) {
    return res.status(400).json({ error: 'Invalid marks. Please enter a number between 0 and 100.' });
  }

  // Update marks
  student.marks = marks;
  res.json({ message: 'Marks updated successfully', updatedStudent: student });
});

// Start the server
app.listen(port, () => {
  console.log(`✅ Server is running at http://localhost:${port}`);
});


// got ot http://localhost:3000/students