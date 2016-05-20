var fs = require('fs');
var exec = require("child_process").exec;

var tests_in = [];
var tests_out = {};
var all_passed = false;

if(!process.argv[2] || !process.argv[3]){
    console.log("Usage: node test.js bin_file test_dir");
}

var bin = process.argv[2];
var test_dir = process.argv[3];

fs.readdirSync(test_dir).map(file=>{
    if(/^.*\.in$/.test(file))tests_in.push(file);
    else{
        var m = file.match(/^(.*)\.out$/);
        if(m!==null){
            tests_out[m[1]+".in"]=fs.readFileSync(test_dir+file).toString().replace("\n","");
        }
    }
});

function loop(n){
    test = tests_in[n];
    console.log("\033[33m"+test);
    exec(`${bin} < ${test_dir}/${test}`,(code,stdout,stderr)=>{
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
        if(++n<tests_in.length)
            setTimeout(()=>loop(n),0);
        else
            console.timeEnd("All tests");
    })
};
console.time("All tests");
loop(0);
