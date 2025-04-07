const express = require("express");  
const path = require("path");  

const app = express();  
const PORT = 3000; 

app.get("/", (req, res) => {
    res.send("Server is running! Click <a href='/download'>download </a> to get the image.");
});


app.get("/download", (req, res) => {  
    const filePath = path.join(__dirname,"image.jpg"); 
    res.download(filePath, "downloadedimage.jpg", (err) => {  
        if (err) {  
            console.error("Error downloading the file:", err);  
            res.status(500).send("Error downloading the file");  
        }  
    });  
});  


app.listen(PORT, () => {  
    console.log(`Server is running on http://localhost:${PORT}`);  
});

//to run the code
//1. run npm install express
//2. save a jpg file(image) in the same folder as server.js (i.e in slip10q1)
//3. run node slip10q1/server.js
//4. the downloaded image is now placed in the sams folder