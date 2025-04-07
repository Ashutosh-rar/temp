const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let ticket = {};

rl.question('Enter passenger name: ', (name) => {
  ticket.name = name;

  rl.question('Enter train name: ', (train) => {
    ticket.train = train;

    rl.question('Enter seat number: ', (seat) => {
      ticket.seat = seat;

      rl.question('Enter journey date (YYYY-MM-DD): ', (date) => {
        ticket.date = date;

        const ticketText = `
======= Railway eTicket =======
Passenger Name : ${ticket.name}
Train Name     : ${ticket.train}
Seat No        : ${ticket.seat}
Date of Journey: ${ticket.date}
==============================
        `;

        fs.writeFile('eticket.txt', ticketText, (err) => {
          if (err) console.error('Error saving ticket:', err);
          else console.log('✅ eTicket generated:\n', ticketText);
          rl.close();
        });
      });
    });
  });
});
