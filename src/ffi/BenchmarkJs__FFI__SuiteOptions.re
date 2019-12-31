module Impl = (T: {
                 type t;
                 type eventHandler;
               }) => {
  [@bs.get] external getName: T.t => string = "name"; // TODO: needs tests
  [@bs.get] external getOnAbort: T.t => T.eventHandler = "onAbort";
  [@bs.get] external getOnComplete: T.t => T.eventHandler = "onComplete";
  [@bs.get] external getOnCycle: T.t => T.eventHandler = "onCycle";
  [@bs.get] external getOnError: T.t => T.eventHandler = "onError";
  [@bs.get] external getOnReset: T.t => T.eventHandler = "onReset";
  [@bs.get] external getOnStart: T.t => T.eventHandler = "onStart";

  [@bs.set] [@bs.scope "options"] external setName: (T.t, string) => unit = "name";
  [@bs.set] external setOnAbort: (T.t, T.eventHandler) => unit = "onAbort";
  [@bs.set] external setOnComplete: (T.t, T.eventHandler) => unit = "onComplete";
  [@bs.set] external setOnCycle: (T.t, T.eventHandler) => unit = "onCycle";
  [@bs.set] external setOnError: (T.t, T.eventHandler) => unit = "onError";
  [@bs.set] external setOnReset: (T.t, T.eventHandler) => unit = "onReset";
  [@bs.set] external setOnStart: (T.t, T.eventHandler) => unit = "onStart";
};