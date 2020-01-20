#pragma once
#include "ChangeLogItem.h"

namespace PaymentofInternetAccess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;

	/// <summary>
	/// Сводка для AddComputer
	/// </summary>
	public ref class AddComputer : public System::Windows::Forms::Form
	{
	public:
		AddComputer(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
			SqlConnection^ connect = gcnew SqlConnection(db);
			SqlCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT MAX(Computer_number) FROM Computers";
			command->Connection = connect;
			SqlDataReader^ dr;
			connect->Open();
			dr = command->ExecuteReader();
			dr->Read();
			if (dr->HasRows)
			{
				textBox1->Text = Convert::ToString(Convert::ToInt32(dr[0]) + 1);
			}
			else
			{
				textBox1->Text = "1";
			}
			dr->Close();
			connect->Close();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddComputer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	public:
		bool f_validate = false;
		Form^ general;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox1;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddComputer::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(37, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Номер компьютера:";
			this->toolTip1->SetToolTip(this->label1, L"Это поле заполняется автоматически.");
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(40, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(163, 20);
			this->textBox1->TabIndex = 1;
			this->toolTip1->SetToolTip(this->textBox1, L"Это поле заполняется автоматически.");
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(37, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"IP адрес:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 156);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Добавить строку";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddComputer::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(158, 156);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Выйти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AddComputer::button2_Click);
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Culture = (gcnew System::Globalization::CultureInfo(L"rw-RW"));
			this->maskedTextBox1->Location = System::Drawing::Point(40, 101);
			this->maskedTextBox1->Mask = L"990.990.990.990";
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(163, 20);
			this->maskedTextBox1->TabIndex = 6;
			this->maskedTextBox1->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddComputer::maskedTextBox1_Validating);
			// 
			// AddComputer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(245, 205);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddComputer";
			this->Text = L"Добавить компьютер";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AddComputer::AddComputer_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (f_validate)
		{
			String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
			SqlConnection^ connect = gcnew SqlConnection(db);
			SqlCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT IP_adress FROM Computers WHERE IP_adress = \'" + this->maskedTextBox1->Text + "\'";
			command->Connection = connect;
			SqlDataReader^ dr;
			connect->Open();
			dr = command->ExecuteReader();
			dr->Read();
			if (!(dr->HasRows))
			{
				ChangeLogItem^ ch = gcnew ChangeLogItem("Computers", "INSERT");
			ch->fill_row_update("IP_adress", "\'" + this->maskedTextBox1->Text + "\'");
			ch->applyChange();
			MessageBox::Show("Строка успешно добавлена!");
			textBox1->Text = Convert::ToString(Convert::ToInt32(textBox1->Text) + 1);
			}
			else
			{
				MessageBox::Show("Ошибка! Строка с таким IP адресом уже существует!");
			}
			dr->Close();
			connect->Close();
		}
		else
		{
			MessageBox::Show("Ошибка ввода!");
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		general->Enabled = true;
		this->Close();
	}
private: System::Void maskedTextBox1_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
{
	
	String^ str = maskedTextBox1->Text;
	str = str->Replace(",", ".")->Replace(" ", "");
	if (System::Net::IPAddress::TryParse(str, gcnew System::Net::IPAddress(0)))
	{
		f_validate = true;
	}
	else
	{
		f_validate = false;
	}
}
private: System::Void AddComputer_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
{
	general->Enabled = true;
}
};
}
