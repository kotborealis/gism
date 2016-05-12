'use strict';

const fs = require('fs');
const exec = require("child_process").exec;

const tests_in = [];
const tests_out = {};

fs.readdirSync("./tests/").map(file=>{
	if(/^.*\.in$/.test(file))tests_in.push(file);
	else{
		const m = file.match(/^(.*)\.out$/);
		if(m!==null){
			tests_out[m[1]+".in"]=fs.readFileSync("./tests/"+file).toString().replace("\n","");
		}
	}
});

tests_in.sort((a,b)=>a.slice(4,-3)*1>b.slice(4,-3)*1).map(test=>exec('./ism < tests/'+test,(code,stdout,stderr)=>{
	const out = stdout.split("\n").slice(0,-1);
	console.log(JSON.stringify({
		name:test,
		time:out.length>=2?out[0]:-1,
		passed:out.length>=2?out[1]===tests_out[test]:out[0]===tests_out[test]
	}));
}));
