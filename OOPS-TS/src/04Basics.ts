class Student {

    constructor(
        private _name: string,
        private _age: number
    ) { }
    
    public set name(name: string) {
        this._name = name
    }

    public set age(age: number) {
        this._age = age
    }

    public get name(): string{
        return this._name
    }

    public get age(): number{
        return this._age
    }
}

const s1 = new Student("Abhi", 20);
s1.name = "Rajan"
s1.age = 40

console.log(s1.name)
console.log(s1.age)