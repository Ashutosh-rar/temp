const fs = require('fs');
const path = require('path');

// Create directory
const dirPath = path.join(__dirname, 'myFolder');
if (!fs.existsSync(dirPath)) {
  fs.mkdirSync(dirPath);
  console.log('Directory created:', dirPath);
}

// Create some files
fs.writeFileSync(path.join(dirPath, 'file1.txt'), 'Hello from file1');
fs.writeFileSync(path.join(dirPath, 'file2.txt'), 'Hello from file2');

// Read directory contents
fs.readdir(dirPath, (err, files) => {
  if (err) {
    return console.error(err);
  }
  console.log('Contents of directory:');
  files.forEach(file => {
    console.log(file);
  });
});
