const express = require('express');
const app = express();
const port = 3000;

app.use(express.urlencoded({ extended: true }));

app.get('/', (req, res) => {
  res.send(`<form action='/buffer' method='post'>
    Buffer 1: <input type='text' name='buffer1'/><br>
    Buffer 2: <input type='text' name='buffer2'/><br>
    <button type='submit'>Submit</button>
  </form>`);
});

app.post('/buffer', (req, res) => {
  const buf1 = Buffer.from(req.body.buffer1);
  const buf2 = Buffer.from(req.body.buffer2);
  res.send(`
    Concatenated: ${Buffer.concat([buf1, buf2]).toString()}<br>
    Comparison: ${buf1.compare(buf2) === 0 ? 'Equal' : buf1.compare(buf2) < 0 ? 'Buffer 1 < Buffer 2' : 'Buffer 1 > Buffer 2'}<br>
    Copied: ${Buffer.from(buf1).toString()}
  `);
});

app.listen(port, () => console.log(`Server running at http://localhost:${port}`));
