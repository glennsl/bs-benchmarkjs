
let () = {

  open Glennsl__BsBenchmarkJs;

  Suite.(

    make("String To Uppercase")
    |> onStart((. _) => Js.log("-- Running Benchmarks --\r\n"))
    |> onError((. evt) => Event.type_(evt) |> Js.log)
    |> onComplete((. _) => Js.log("-- Done --\r\n"))

    |> add("Map Char Function", (. ) => {
      let result = ref("");
      result := result^ ++ "Hello Benchmark.js!"
      result := result^ |> String.map((character) => Char.uppercase_ascii(character));
    })

    |> add("Use String Function", (. ) => {
      let result = ref("");
      result := result^ ++ "Hello Benchmark.js!"
      result := result^ |> String.uppercase_ascii;
    })

    |> run

    |> toList
    |> List.iter( benchmark =>
        Benchmark.toString(benchmark)
        |> Js.log
      )

  );

};