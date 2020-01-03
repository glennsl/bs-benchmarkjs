open Glennsl__BsBenchmarkJs__2;

let suite: Suite.t =
  Suite.(
    make("PerfTest")
    |> add("test0", (.) => ())
    |> onStart((. _) => Js.log("-- Running Tests --"))
    |> onError((. evt) => Event.getType(evt) |> Js.log)
    |> (thisSuite => onComplete((. _) => Js.log("Done"), thisSuite)
    |> run)
  );