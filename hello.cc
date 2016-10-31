#include <node.h>
#include <v8.h>

using namespace v8;

void Method(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void MyMethod(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  printf("Running C code\n");
  fflush(stdout);
}

void Init(Handle<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  exports->Set(String::NewFromUtf8(isolate, "hello"),
      FunctionTemplate::New(isolate, Method)->GetFunction());
  exports->Set(String::NewFromUtf8(isolate, "printy"),
      FunctionTemplate::New(isolate, MyMethod)->GetFunction());
}

NODE_MODULE(hello, Init)
