/*
    We delete the body assignments and the top declarations. The constructor arguments become the properties.
*/

class Student {
  // NOTE: // 1. NO declarations at the top.

  // 2. Add 'public' to EVERY argument you want to be a property.
    constructor(
        public name: string,
        public age: number,
        public grade: string
    ) {

      // NOTE:
      // 3. Empty Body!
      // TypeScript automatically does "this.name = name" for you.
    }
}

const s1 = new Student("Mohan", 20, "A+")
console.log(s1.name)