import { readFileSync } from "fs";


function ReadFile1() {

    const s: string[][] = [];

    const contents = readFileSync('./input.txt', 'utf-8');

    const arr = contents.split(/\r?\n/);

    let index = 0;
    let count = 0;
    for (let i = 0; i < 35; i++) {
        s[index] = [];
        for (let k = 7; k >= 0; k--) {
            if (arr[k].charAt(i) !== ' ' && arr[k].charAt(i) !== '[' && arr[k].charAt(i) !== ']') {

                s[index].push(arr[k].charAt(i));
            }
        }
        if (i === 1 || i === 5 || i === 9 || i === 13 || i === 17 || i === 21 || i === 25 || i === 29 || i === 33) {
            index++;
        }
    }

    for (let i = 10; i < 511; i++) {
        // [0] how many should be moved
        // [1] - 1 from stack
        // [2] - 1 to stack
        let numbers = arr[i].replace(/\D/g, '');
        let index1 = +numbers.charAt(0);
        let index2 = +numbers.charAt(1) - 1;
        let index3 = +numbers.charAt(2) - 1;

        if (numbers.length > 3) {
            index2 = +numbers.charAt(2) - 1;
            index3 = +numbers.charAt(3) - 1;
            index1 = +numbers.slice(0, 2)

        }
        let queue: string[] = [];
        for (let k = 0; k < index1; k++) {
            queue[k] = s[index2].pop()!;
        }
        for (let k = 0; k < index1; k++) {
            s[index3].push(queue.shift()!);            
        }
    }

    let output = ''
    for (let i = 0; i < s.length - 1; i++) {
        output += s[i][s[i].length - 1];
    }

    // sol 1
    console.log(output)

}

function ReadFile2() {

    const s: string[][] = [];

    const contents = readFileSync('./input.txt', 'utf-8');

    const arr = contents.split(/\r?\n/);

    let index = 0;
    let count = 0;
    for (let i = 0; i < 35; i++) {
        s[index] = [];
        for (let k = 7; k >= 0; k--) {
            if (arr[k].charAt(i) !== ' ' && arr[k].charAt(i) !== '[' && arr[k].charAt(i) !== ']') {

                s[index].push(arr[k].charAt(i));
            }
        }
        if (i === 1 || i === 5 || i === 9 || i === 13 || i === 17 || i === 21 || i === 25 || i === 29 || i === 33) {
            index++;
        }
    }

    for (let i = 10; i < 511; i++) {
        // [0] how many should be moved
        // [1] - 1 from stack
        // [2] - 1 to stack
        let numbers = arr[i].replace(/\D/g, '');

        let index : number[] = [];

        index[0] = +numbers.charAt(0);
        index[1] = +numbers.charAt(1) - 1;
        index[2] = +numbers.charAt(2) - 1;

        if (numbers.length > 3) {
            index[1] = +numbers.charAt(2) - 1;
            index[2] = +numbers.charAt(3) - 1;
            index[0] = +numbers.slice(0, 2)
        }
        
        let stack: string[] = [];
        for (let k = 0; k < index[0]; k++) {
            stack[k] = s[index[1]].pop()!;
        }
        for (let k = 0; k < index[0]; k++) {
            s[index[2]].push(stack.pop()!);            
        }
    }

    let output = ''
    for (let i = 0; i < s.length - 1; i++) {
        output += s[i][s[i].length - 1];
    }

    // sol 2
    console.log(output)

}

ReadFile1()

ReadFile2()