
module type Intf = {
  let browser: bool;
  let decompilation: bool;
  let timeout: bool;
};

module Impl = {
  module Internal = BenchmarkJs__FFI__Support;
  let browser: bool = Internal.(getBrowser(data));
  let decompilation: bool = Internal.(getDecompilation(data));
  let timeout: bool = Internal.(getTimeout(data));
};

include (Impl: Intf);
