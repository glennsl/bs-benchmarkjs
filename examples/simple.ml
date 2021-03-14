open Benchmark

let () =
  makeSuite "Find Char"
  |> add "RegExp#test" (fun () -> "Hello World!"|> Js.Re.test_ [%re "/o/"] |> ignore)
  |> add "String#indexOf" (fun () -> "Hello World!" |> Js.String.indexOf "o" |> ignore)
  |> add "String#match"   (fun () -> "Hello World!" |> Js.String.match_ [%re "/o/"] |> ignore)
  |> on "start cycle" (fun event ->
    let name = event##target##name in
    Js.log {j|Running $name...|j}
  )
  |> on "cycle" (fun event ->
    Js.log (Js.String.make event##target)
  )
  |> run ()
