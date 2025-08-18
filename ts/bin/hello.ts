// VECTOR
let vec: number[] = [1, 2, 3, 4, 5];
vec.push(6);

for (let i = 0; i < vec.length; i++){
	vec[i] += 5;
}

for (let num of vec) {
	console.log(num);

}

// SET
let s: Set<number> = new Set();
s.add(5);
s.add(5);
s.add(6);
