const express = require('express');
const path = require('path');
const app = express();
const port = 3000;


app.set('view engine', 'ejs');


app.set('views', path.join(__dirname)); 

app.get('/', (req, res) => {
    const courseStructure = {
        semester3: [
            { code: 'CA-301', name: 'Digital Marketing' },
            { code: 'CA-302', name: 'Data Structure' },
            { code: 'CA-303', name: 'Software Engineering' },
            { code: 'CA-304', name: 'Angular - JS' },
            { code: 'CA-305', name: 'BlockChain' },
        ],
        semester4: [
            { code: 'CA-401', name: 'Networking' },
            { code: 'CA-402', name: 'Object Oriented Concepts Through CPP' },
            { code: 'CA-403', name: 'Operating System' },
            { code: 'CA-404', name: 'Node - JS' },
        ]
    };
    res.render('index', { courseStructure }); 
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});
