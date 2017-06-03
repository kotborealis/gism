/*

  There's a bug: if you run all tests, ["test_b24", "test_b30", "test_b36"] will fail.
  If you run ONLY ["test_b24", "test_b30", "test_b36"], it's working just fine.

 */
const tests = ["test1", "test2", "test3", "test4", "test5", "test6", "test7", "test_a0", "test_a10", "test_a11", "test_a12", "test_a13", "test_a14", "test_a15", "test_a16", "test_a17", "test_a18", "test_a19", "test_a1", "test_a20", "test_a2", "test_b0", "test_b10", "test_b11", "test_b12", "test_b13", "test_b14", "test_b15", "test_b16", "test_b17", "test_b18", "test_b19", "test_b1", "test_b20", "test_b21", "test_b22", "test_b23", "test_b24", "test_b25", "test_b26", "test_b27", "test_b28", "test_b29", "test_b2", "test_b30", "test_b31", "test_b32", "test_b33", "test_b34", "test_b35", "test_b36", "test_b3", "test_b4", "test_b5", "test_b6", "test_b7", "test_b8", "test_b9"];
// const tests = ["test_b24", "test_b30", "test_b36"];

let tests_passed = [];
let tests_failed = [];

let timeStartAll = 0;

const main = () => {
  let buf = '';

  buf += `<font color="cyan">`;
  buf += "-".repeat(50) + "<br/>";
  buf += `Running ${tests.length} tests.<br/>`;
  buf += "-".repeat(50) + "<br/>";
  buf += `</font>`;

  postMessage(buf);

  timeStartAll = Date.now();

  loop(0);
};

const loop = async (n) => {
  let buf = '';

  if(!tests[n]){
    final();
    return;
  }

  const in_data = (await (await fetch(`./tests/${tests[n]}.in`)).text()).trim();
  const out_data = (await (await fetch(`./tests/${tests[n]}.out`)).text()).trim();

  const expected = out_data === "YES";

  buf += ' '.repeat(15).substr(0,15 - tests[n].length);
  buf += `<font color="cyan">${tests[n]}...</font>`
  buf += ' '.repeat(5);
  postMessage(buf); buf = '';

  const startTime = Date.now();
  const res = Module.process(in_data);
  const time = Date.now() - startTime;

  const passed = expected === res;

  if(passed){
    tests_passed.push(tests[n]);
  }
  else{
    tests_failed.push(tests[n]); 
  }

  buf += `<font color="${passed ? 'green' : 'red'}">`;
  buf += passed ? 'OK' : 'ERROR';
  buf += ` [${time/1000}]`;
  buf += `Expected: ${out_data}/${expected}, Got: ${res}`
  buf += `</font><br/>`;
  postMessage(buf); buf = '';

  loop(n+1);
};

const final = () => {
  let buf = '';

  buf += `<font color="cyan">`;
  buf += "-".repeat(50) + "<br/>";
  buf += `</font>`;

  buf += `<font color="cyan">Total time: ${(Date.now() - timeStartAll)/1000}</font></br>`;
  
  buf += `<font color="green">OK: ${tests_passed.length}</font><br/>`;
  buf += `<font color="red">ERROR: ${tests_failed.length}</font><br/>`;

  buf += `<font color="cyan">`;
  buf += "-".repeat(50) + "<br/>";
  buf += `</font>`;

  postMessage(buf);
};

var Module = {
  onRuntimeInitialized: main
};

importScripts("index.js");