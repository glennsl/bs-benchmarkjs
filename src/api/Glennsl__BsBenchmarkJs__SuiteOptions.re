module Impl = (T: {
                 type t;
                 type eventHandler;
               }) => {
  module Internal = {
    include Glennsl__BsBenchmarkJs__FFI.SuiteOptions.Impl(T);
    let nullToOption = Js.Nullable.toOption;
  };

  let getName: T.t => option(string) = name => Internal.(getName(name)->nullToOption);

  let getOnAbort: T.t => option(T.eventHandler) =
    onAbort => Internal.(getOnAbort(onAbort)->nullToOption);

  let getOnComplete: T.t => option(T.eventHandler) =
    onComplete => Internal.(getOnComplete(onComplete)->nullToOption);

  let getOnCycle: T.t => option(T.eventHandler) =
    onCycle => Internal.(getOnCycle(onCycle)->nullToOption);

  let getOnError: T.t => option(T.eventHandler) =
    onError => Internal.(getOnError(onError)->nullToOption);

  let getOnReset: T.t => option(T.eventHandler) =
    onReset => Internal.(getOnReset(onReset)->nullToOption);

  let getOnStart: T.t => option(T.eventHandler) =
    onStart => Internal.(getOnStart(onStart)->nullToOption);

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
};