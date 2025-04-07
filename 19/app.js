const express = require('express');
const axios = require('axios');

const app = express();
const port = 3000;

app.set('view engine', 'ejs');

// Fetch top stories from Hacker News API
app.get('/', async (req, res) => {
    try {
        const { data: storyIds } = await axios.get('https://--');
        const stories = await Promise.all(
            storyIds.slice(0, 10).map(async (id) => {
                const { data: story } = await axios.get(`https://--`);
                return story;
            })
        );
        res.render('index', { stories });
    } catch (error) {
        res.status(500).send('Error fetching stories');
    }
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});

//create index.html
//npm install express axios
//run node app.js


