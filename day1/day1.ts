import { readFileSync } from "fs";

class stack {
    num: number[] = [];

    push(x: any) {
        this.num.push(+x);
    }
    sumStack() {
        let x : number = 0;
        for(let i in this.num){
            x += this.num[i];
        }
        this.num.length = 0;
        return x;
    }
}

function ReadFile() {

    const s : stack = new stack();


    const contents = readFileSync('./input.txt', 'utf-8');

    const arr = contents.split(/\r?\n/);
    
    let sum : number[] = [];

    for(let i in arr) {
        if(arr[i] === ''){
            sum.push(s.sumStack());
        }
        else {
            s.push(+arr[i]);
        }
    }

    // 1st solution
    console.log(Math.max(...sum));

    // 2nd solution
    sum.sort();

    let top3 = sum[sum.length-2] + sum[sum.length-3] + sum[sum.length-4];

    console.log(top3);
}

ReadFile()
