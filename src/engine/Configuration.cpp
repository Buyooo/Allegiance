#include "Configuration.h"

void UpdatingConfiguration::Write() {
    auto mapBool = mBoolMap->GetMap();
    for (auto it = mapBool.begin(); it != mapBool.end(); ++it)
    {
        m_inner->SetBool(it->first, it->second->GetValue());
    }

    auto mapFloat = mFloatMap->GetMap();
    for (auto it = mapFloat.begin(); it != mapFloat.end(); ++it)
    {
        m_inner->SetFloat(it->first, it->second->GetValue());
    }

    auto mapInt = mIntMap->GetMap();
    for (auto it = mapInt.begin(); it != mapInt.end(); ++it)
    {
        m_inner->SetInt(it->first, (int)it->second->GetValue());
    }

    auto mapString = mStringMap->GetMap();
    for (auto it = mapString.begin(); it != mapString.end(); ++it)
    {
        m_inner->SetString(it->first, std::string(it->second->GetValue()));
    }

    m_inner->Commit();
}

const TRef<SimpleModifiableValue<bool>>& UpdatingConfiguration::GetBool(std::string key, bool valueDefault) {
    if (mBoolMap->Has(key) == false) {
        mBoolMap->Set(key, m_inner->ReadBool(key, valueDefault));
    }
    return mBoolMap->Get(key);
}

bool UpdatingConfiguration::GetBoolValue(std::string key, bool valueDefault) {
    if (mBoolMap->Has(key) == false) {
        return valueDefault;
    }
    return mBoolMap->Get(key)->GetValue();
}

const TRef<SimpleModifiableValue<float>>& UpdatingConfiguration::GetFloat(std::string key, float valueDefault) {
    if (mFloatMap->Has(key) == false) {
        mFloatMap->Set(key, m_inner->ReadFloat(key, valueDefault));
    }
    return mFloatMap->Get(key);
}

float UpdatingConfiguration::GetFloatValue(std::string key, float valueDefault) {
    if (mFloatMap->Has(key) == false) {
        return valueDefault;
    }
    return mFloatMap->Get(key)->GetValue();
}

const TRef<SimpleModifiableValue<float>>& UpdatingConfiguration::GetInt(std::string key, int valueDefault) {
    if (mIntMap->Has(key) == false) {
        mIntMap->Set(key, (float)m_inner->ReadInt(key, valueDefault));
    }
    return mIntMap->Get(key);
}

int UpdatingConfiguration::GetIntValue(std::string key, int valueDefault) {
    if (mIntMap->Has(key) == false) {
        return valueDefault;
    }
    return (int)mIntMap->Get(key)->GetValue();
}

const TRef<SimpleModifiableValue<ZString>>& UpdatingConfiguration::GetString(std::string key, const std::string& valueDefault) {
    if (mStringMap->Has(key) == false) {
        mStringMap->Set(key, m_inner->ReadString(key, valueDefault).c_str());
    }
    return mStringMap->Get(key);
}

std::string UpdatingConfiguration::GetStringValue(std::string key, const std::string& valueDefault) {
    if (mStringMap->Has(key) == false) {
        return valueDefault;
    }
    return std::string(mStringMap->Get(key)->GetValue());
}