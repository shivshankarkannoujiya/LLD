class Student {
    private _marks: number

    constructor(marks: number) {
        this._marks = marks
    }

    // getter
    public get marks(): number{
        return this._marks
    }

    // setter
    public set marks(value: number) {
        if (value < 0) {
            console.log(`ERROR: Mark should be positive`)
            return
        }

        if (value > 100) {
            console.log(`"Error: Are you a vampire?"`);
            return
        }

        this._marks = value
    }
}

const s1 = new Student(30)

// Using the SETTER (Looks like a variable, behaves like a function)
s1.marks = 90 // setter
console.log(s1.marks) // getter
