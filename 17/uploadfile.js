const express = require('express');
const path = require('path');

const app = express();
const PORT = 3000;


app.get('/download', (req, res) => {
    const filePath = path.join(__dirname, 'file1.txt'); // file name
    res.download(filePath, 'DownloadedFile.txt', (err) => {
        if (err) {
            console.error('Error sending file:', err);
            res.status(500).send('Error downloading file');
        }
    });
});

app.get('/', (req, res) => {
    res.send('Welcome! Go to <a href="/download">Download</a> to get the file.');
});

app.listen(PORT, () => {
    console.log(`Server is running at http://localhost:${PORT}`);
});

//run node uploadfile.js
//create file1.txt file
