const express = require('express');
const cors = require('cors');
const app = express();
const port = 3000;

app.use(express.json());
app.use(cors()); // Allows frontend to communicate with backend

let courses = [{ id: 1, title: 'Node.js' }, { id: 2, title: 'JavaScript' }];
let users = [{ id: 1, name: 'John', enrolled: [] }];

app.get('/', (req, res) => res.send('Server is running...'));
app.get('/courses', (req, res) => res.json(courses));

app.post('/enroll', (req, res) => {
  const { userId, courseId } = req.body;
  let user = users.find(u => u.id === userId);
  if (!user) return res.status(400).json({ error: 'User not found' });

  if (!courses.find(c => c.id === courseId)) 
    return res.status(400).json({ error: 'Course not found' });

  if (user.enrolled.includes(courseId)) 
    return res.status(400).json({ error: 'Already enrolled' });

  user.enrolled.push(courseId);
  res.json({ message: 'Enrolled successfully' });
});

app.listen(port, () => console.log(`Server running at http://localhost:${port}`));
