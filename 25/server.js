const express = require("express");
const fs = require("fs");

const app = express();
const PORT = 3000;

app.get("/", (req, res) => {
    const today = new Date().toISOString().split("T")[0];

    fs.readFile("events.json", "utf8", (err, data) => {
        if (err) {
            res.status(500).send("Error reading events file");
            return;
        }

        const events = JSON.parse(data);
        const todaysEvents = events.filter(event => event.date === today);

        if (todaysEvents.length === 0) {
            res.send(`<h2>No events for today (${today})</h2>`);
        } else {
            let eventList = todaysEvents.map(e => `<li>${e.event}</li>`).join("");
            res.send(`<h2>Events for Today (${today}):</h2><ul>${eventList}</ul>`);
        }
    });
});

app.listen(PORT, () => console.log(`Server running on http://localhost:${PORT}`));
