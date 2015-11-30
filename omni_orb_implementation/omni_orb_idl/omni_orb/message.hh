// This file is generated by omniidl (C++ backend)- omniORB_4_2. Do not edit.
#ifndef __message_hh__
#define __message_hh__

#ifndef __CORBA_H_EXTERNAL_GUARD__
#include <omniORB4/CORBA.h>
#endif

#ifndef USE_stub_in_nt_dll
# define USE_stub_in_nt_dll_NOT_DEFINED_message
#endif
#ifndef USE_core_stub_in_nt_dll
# define USE_core_stub_in_nt_dll_NOT_DEFINED_message
#endif
#ifndef USE_dyn_stub_in_nt_dll
# define USE_dyn_stub_in_nt_dll_NOT_DEFINED_message
#endif


#ifdef USE_stub_in_nt_dll
# ifndef USE_core_stub_in_nt_dll
#  define USE_core_stub_in_nt_dll
# endif
# ifndef USE_dyn_stub_in_nt_dll
#  define USE_dyn_stub_in_nt_dll
# endif
#endif

#ifdef _core_attr
# error "A local CPP macro _core_attr has already been defined."
#else
# ifdef USE_core_stub_in_nt_dll
#  define _core_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _core_attr
# endif
#endif

#ifdef _dyn_attr
# error "A local CPP macro _dyn_attr has already been defined."
#else
# ifdef USE_dyn_stub_in_nt_dll
#  define _dyn_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _dyn_attr
# endif
#endif


#ifndef __MessageIdl__
#define __MessageIdl__
class MessageIdl;
class _objref_MessageIdl;
class _impl_MessageIdl;

typedef _objref_MessageIdl* MessageIdl_ptr;
typedef MessageIdl_ptr MessageIdlRef;

class MessageIdl_Helper
{
	public:
	typedef MessageIdl_ptr _ptr_type;

	static _ptr_type _nil();
	static _CORBA_Boolean is_nil(_ptr_type);
	static void release(_ptr_type);
	static void duplicate(_ptr_type);
	static void marshalObjRef(_ptr_type, cdrStream&);
	static _ptr_type unmarshalObjRef(cdrStream&);
};

typedef _CORBA_ObjRef_Var<_objref_MessageIdl, MessageIdl_Helper> MessageIdl_var;
typedef _CORBA_ObjRef_OUT_arg<_objref_MessageIdl, MessageIdl_Helper> MessageIdl_out;

#endif

// interface MessageIdl
class MessageIdl
{
	public:
	// Declarations for this interface type.
	typedef MessageIdl_ptr _ptr_type;
	typedef MessageIdl_var _var_type;

	static _ptr_type _duplicate(_ptr_type);
	static _ptr_type _narrow(::CORBA::Object_ptr);
	static _ptr_type _unchecked_narrow(::CORBA::Object_ptr);

	static _ptr_type _nil();

	static inline void _marshalObjRef(_ptr_type, cdrStream&);

	static inline _ptr_type _unmarshalObjRef(cdrStream& s)
	{
		omniObjRef* o = omniObjRef::_unMarshal(_PD_repoId, s);
		if (o)
			return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
		else
			return _nil();
	}

	static inline _ptr_type _fromObjRef(omniObjRef* o)
	{
		if (o)
			return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
		else
			return _nil();
	}

	static _core_attr const char* _PD_repoId;

	// Other IDL defined within this scope.
};

class _objref_MessageIdl :
	public virtual ::CORBA::Object,
	public virtual omniObjRef
{
	public:
	// IDL operations
	char *getContent();
	void setContent(const char* text);

	// Constructors
	inline _objref_MessageIdl()
	{
		_PR_setobj(0);
	} // nil
	_objref_MessageIdl(omniIOR*, omniIdentity*);

	protected:
	virtual ~_objref_MessageIdl();


	private:
	virtual void *_ptrToObjRef(const char*);

	_objref_MessageIdl(const _objref_MessageIdl&);
	_objref_MessageIdl &operator =(const _objref_MessageIdl&);
	// not implemented

	friend class MessageIdl;
};

class _pof_MessageIdl : public _OMNI_NS(proxyObjectFactory)

{
	public:
	inline _pof_MessageIdl() : _OMNI_NS(proxyObjectFactory)

	(MessageIdl::_PD_repoId){}

	virtual ~_pof_MessageIdl();

	virtual omniObjRef *newObjRef(omniIOR*, omniIdentity*);
	virtual _CORBA_Boolean is_a(const char*) const;
};

class _impl_MessageIdl :
	public virtual omniServant
{
	public:
	virtual ~_impl_MessageIdl();

	virtual char *getContent() = 0;
	virtual void setContent(const char* text) = 0;

	public: // Really protected, workaround for xlC
	virtual _CORBA_Boolean _dispatch(omniCallHandle&);

	private:
	virtual void *_ptrToInterface(const char*);
	virtual const char *_mostDerivedRepoId();
};


class POA_MessageIdl :
	public virtual _impl_MessageIdl,
	public virtual ::PortableServer::ServantBase
{
	public:
	virtual ~POA_MessageIdl();

	inline ::MessageIdl_ptr _this()
	{
		return (::MessageIdl_ptr) _do_this(::MessageIdl::_PD_repoId);
	}
};


#undef _core_attr
#undef _dyn_attr


inline void MessageIdl::_marshalObjRef(::MessageIdl_ptr obj, cdrStream& s)
{
	omniObjRef::_marshal(obj->_PR_getobj(), s);
}


#ifdef USE_stub_in_nt_dll_NOT_DEFINED_message
# undef USE_stub_in_nt_dll
# undef USE_stub_in_nt_dll_NOT_DEFINED_message
#endif
#ifdef USE_core_stub_in_nt_dll_NOT_DEFINED_message
# undef USE_core_stub_in_nt_dll
# undef USE_core_stub_in_nt_dll_NOT_DEFINED_message
#endif
#ifdef USE_dyn_stub_in_nt_dll_NOT_DEFINED_message
# undef USE_dyn_stub_in_nt_dll
# undef USE_dyn_stub_in_nt_dll_NOT_DEFINED_message
#endif

#endif // __message_hh__

