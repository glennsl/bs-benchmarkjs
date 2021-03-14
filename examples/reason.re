open Benchmark;

let () =
  makeSuite("Find Char")
  |> add("RegExp#test", () =>
       [%re "/o/"]->Js.Re.test_(_, "Hello World!") |> ignore
     )
  |> add("String#indexOf", () =>
       "Hello World!" |> Js.String.indexOf("o") |> ignore
     )
  |> add("String#match", () =>
       "Hello World!" |> Js.String.match([%re "/o/"]) |> ignore
     )
  |> on("start cycle", event => {
       let name = event##target##name;
       Js.log({j|Running $name...|j});
     })
  |> on("cycle", event => Js.log(Js.String.make(event##target)))
  |> run();
