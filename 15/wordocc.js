var fs=require("fs");
function countOcc(string,word){
 return string.split(word).length-1;
}
var text=fs.readFileSync('file1.txt','utf8');
var count=countOcc(text,"cat");
if(count==0){
console.log("not found");
}else{
console.log(count);
}

