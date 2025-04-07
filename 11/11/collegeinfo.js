const http = require('http');


const collegeInfo = `
    <h1>Welcome to Vishwakarma College</h1>
    <p>VCACS College offers various undergraduate and postgraduate courses.</p>
    <p>Location: Pune, India</p>
    <p>Contact: vcacscollege@gmail.com</p>
`;


const server = http.createServer((req, res) => {
    res.writeHead(200, { 'Content-Type': 'text/html' });
    res.end(collegeInfo);
});


const PORT = 3000;
server.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}`);
});

// run node collegeinfo.js in the terminal