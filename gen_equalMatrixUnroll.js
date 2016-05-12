function g(n){a=`bool equalMatrixUnroll${n}(int** a, int**b, int n){\n    return `;for(i=0;i<n;i++)for(j=0;j<n;j++)a+=`a[${i}][${j}]==b[${i}][${j}] && \n    `;a=a.slice(0,-9);return a+";\n}\n"}
for(var i=1;i<=13;i++)
console.log(g(i));