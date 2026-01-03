// class Student {
//     name!: string
//     grade!: string
//     age!: number
//     roll_no!: number

// }

// let s1 = new Student()
// s1.name = "Abhi"


// --------------------------------------

class Student {
    name: string
    grade: string
    age: number
    roll_no: number

    constructor(name: string, grade: string, age: number, roll_number: number) {
        this.name = name
        this.age = age
        this.grade = grade
        this.roll_no = roll_number
    }

}

const studentOne = new Student("Rohan", "A+", 20, 12)
console.log(studentOne)
console.log(studentOne.name)

// ------------------------------------------------------------