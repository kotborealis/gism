var fs = require('fs');
var exec = require("child_process").exec;

var tests_in = [];
var tests_out = {};
var all_passed = false;

fs.readdirSync("./tests/").map(file=>{
    if(/^.*\.in$/.test(file))tests_in.push(file);
    else{
        var m = file.match(/^(.*)\.out$/);
        if(m!==null){
            tests_out[m[1]+".in"]=fs.readFileSync("./tests/"+file).toString().replace("\n","");
        }
    }
});

tests_in.sort((a,b)=>a.slice(4,-3)*1>b.slice(4,-3)*1).map(test=>exec('./ism < tests/'+test,(code,stdout,stderr)=>{
    var out = stdout.split("\n").slice(0,-1);
    var r = {
        name:test,
        time:out.length>=2?Number.parseFloat(out[0].slice(0,-2)):-1,
        passed:out.length>=2?out[1]===tests_out[test]:out[0]===tests_out[test]
    };
    var output="";
    output+=r.passed?"\033[32m":"\033[31m";
    output+=r.passed?"OK":"ERROR";
    output+=` ${r.name} `;
    output+=` [${r.time}]`;
    output+="\033[0m";
    console.log(output);
}));


