function makePerson(first, last, localVar) {
    let l = localVar;
    return {
        first: first,
        last: last,
        fullName() {
            return `${this.first} ${this.last} ${l}`;
        },
        fullNameReversed() {
            return `${this.last}, ${this.first}`;
        }
    };
}
const s = makePerson('Simon', 'Willison', 30);
console.log(s.fullName()); // Simon Willison

const x = makePerson('Harasees', 'Singh', 20);
console.log(x.fullName()); // Harasee Singh

console.log(s.fullName()); // Simon Willison
  