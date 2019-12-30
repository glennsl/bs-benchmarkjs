
module Impl = (T: {
  type t;
  type eventHandler;
}) => {
  module Internal = {
    include BenchmarkJs__FFI.SuiteOptions.Impl({
      type t = T.t;
      type eventHandler = T.eventHandler;
    });
  };

  let getName: T.t => string = Internal.getName;
  let getOnAbort: T.t => T.eventHandler = Internal.getOnAbort;
  let getOnComplete: T.t => T.eventHandler = Internal.getOnComplete;
  let getOnCycle: T.t => T.eventHandler = Internal.getOnCycle;
  let getOnError: T.t => T.eventHandler = Internal.getOnError;
  let getOnReset: T.t => T.eventHandler = Internal.getOnReset;
  let getOnStart: T.t => T.eventHandler = Internal.getOnStart;
  let setName: (string, T.t) => T.t =
    (name, opt) => {
      Internal.setName(opt, name);
      opt;
    };
  let setOnAbort: (T.eventHandler, T.t) => T.t =
    (onAbort, opt) => {
      Internal.setOnAbort(opt, onAbort);
      opt;
    };
  let setOnComplete: (T.eventHandler, T.t) => T.t =
    (onComplete, opt) => {
      Internal.setOnComplete(opt, onComplete);
      opt;
    };
  let setOnCycle: (T.eventHandler, T.t) => T.t =
    (onCycle, opt) => {
      Internal.setOnCycle(opt, onCycle);
      opt;
    };
  let setOnError: (T.eventHandler, T.t) => T.t =
    (onError, opt) => {
      Internal.setOnError(opt, onError);
      opt;
    };
  let setOnReset: (T.eventHandler, T.t) => T.t =
    (onReset, opt) => {
      Internal.setOnReset(opt, onReset);
      opt;
    };
  let setOnStart: (T.eventHandler, T.t) => T.t =
    (onStart, opt) => {
      Internal.setOnStart(opt, onStart);
      opt;
    };

  let make:
    (
      ~name: string=?,
      ~onAbort: T.eventHandler=?,
      ~onComplete: T.eventHandler=?,
      ~onCycle: T.eventHandler=?,
      ~onError: T.eventHandler=?,
      ~onReset: T.eventHandler=?,
      ~onStart: T.eventHandler=?,
      T.t
    ) =>
    T.t =
    (
      ~name: option(string)=?,
      ~onAbort: option(T.eventHandler)=?,
      ~onComplete: option(T.eventHandler)=?,
      ~onCycle: option(T.eventHandler)=?,
      ~onError: option(T.eventHandler)=?,
      ~onReset: option(T.eventHandler)=?,
      ~onStart: option(T.eventHandler)=?,
      opt: T.t,
    ) => {
      let () = {
        switch (name) {
        | None => ()
        | Some(x) => Internal.setName(opt, x)
        };
        switch (onAbort) {
        | None => ()
        | Some(x) => Internal.setOnAbort(opt, x)
        };
        switch (onComplete) {
        | None => ()
        | Some(x) => Internal.setOnComplete(opt, x)
        };
        switch (onCycle) {
        | None => ()
        | Some(x) => Internal.setOnCycle(opt, x)
        };
        switch (onError) {
        | None => ()
        | Some(x) => Internal.setOnError(opt, x)
        };
        switch (onReset) {
        | None => ()
        | Some(x) => Internal.setOnReset(opt, x)
        };
        switch (onStart) {
        | None => ()
        | Some(x) => Internal.setOnStart(opt, x)
        };
      };
      opt;
    };
}

type t = BenchmarkJs__Types.suiteOptions;

include Impl({
  type nonrec t = t;
  type eventHandler = BenchmarkJs__Types.eventHandler;
});
